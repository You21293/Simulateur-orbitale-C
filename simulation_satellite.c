#include <stdio.h>
#include <math.h>

#define G 6.67430e-11
#define MASSE_TERRE 5.972e24
#define RAYON_TERRE 6371000
#define NB_SATELLITES 4

typedef struct
{
    char nom[50];
    double altitude;
    double masse;
    double angle;

    double vitesse;
    double periode;
} Satellite;

/* ========================= */
/* CALCULS PHYSIQUES */
/* ========================= */

double calculVitesse(double altitude)
{
    double r = RAYON_TERRE + altitude;

    return sqrt((G * MASSE_TERRE) / r);
}

double calculPeriode(double altitude)
{
    double r = RAYON_TERRE + altitude;

    return (2 * M_PI * r) /
           calculVitesse(altitude);
}

/* ========================= */
/* INITIALISATION */
/* ========================= */

void initialiserSatellite(
    Satellite *sat,
    char nom[],
    double altitude,
    double masse,
    double angle)
{
    int i = 0;

    while(nom[i] != '\0')
    {
        sat->nom[i] = nom[i];
        i++;
    }

    sat->nom[i] = '\0';

    sat->altitude = altitude;
    sat->masse = masse;
    sat->angle = angle;

    sat->vitesse = calculVitesse(altitude);
    sat->periode = calculPeriode(altitude);
}

/* ========================= */
/* AFFICHAGE */
/* ========================= */

void afficherSatellite(Satellite sat)
{
    printf("\n=============================\n");

    printf("Satellite : %s\n", sat.nom);

    printf("Altitude : %.0f km\n",
           sat.altitude / 1000);

    printf("Masse : %.2f kg\n",
           sat.masse);

    printf("Vitesse : %.2f m/s\n",
           sat.vitesse);

    printf("Periode : %.2f min\n",
           sat.periode / 60.0);
}

/* ========================= */
/* SIMULATION ORBITALE */
/* ========================= */

void simulerOrbite(Satellite sat)
{
    int temps;

    printf("\n--- Simulation %s ---\n",
           sat.nom);

    for(temps = 0;
        temps <= 3600;
        temps += 600)
    {
        double angle =
        fmod(
        (360.0 * temps) /
        sat.periode,
        360.0);

        printf(
        "Temps : %4d s | Angle : %.2f degres\n",
        temps,
        angle);
    }
}

/* ========================= */
/* DISTANCE ENTRE DEUX SAT */
/* ========================= */

double distanceSatellites(
    Satellite s1,
    Satellite s2)
{
    double r1 =
    RAYON_TERRE +
    s1.altitude;

    double r2 =
    RAYON_TERRE +
    s2.altitude;

    double x1 =
    r1 *
    cos(
    s1.angle *
    M_PI /
    180.0);

    double y1 =
    r1 *
    sin(
    s1.angle *
    M_PI /
    180.0);

    double x2 =
    r2 *
    cos(
    s2.angle *
    M_PI /
    180.0);

    double y2 =
    r2 *
    sin(
    s2.angle *
    M_PI /
    180.0);

    return sqrt(
    pow(x2-x1,2)
    +
    pow(y2-y1,2));
}

/* ========================= */
/* PROGRAMME PRINCIPAL */
/* ========================= */

int main()
{
    Satellite flotte[NB_SATELLITES];

    initialiserSatellite(
    &flotte[0],
    "ISS",
    408000,
    420000,
    0);

    initialiserSatellite(
    &flotte[1],
    "Hubble",
    540000,
    11110,
    90);

    initialiserSatellite(
    &flotte[2],
    "Starlink",
    550000,
    260,
    180);

    initialiserSatellite(
    &flotte[3],
    "CubeSat",
    400000,
    12,
    270);

    printf(
    "===================================\n");
    printf(
    " SIMULATEUR D'ORBITE DE SATELLITES\n");
    printf(
    "===================================\n");

    int i;
    int j;

    /* Affichage des données */

    for(i=0;i<NB_SATELLITES;i++)
    {
        afficherSatellite(
        flotte[i]);
    }

    /* Simulation */

    printf(
    "\n\n===== SIMULATION =====\n");

    for(i=0;i<NB_SATELLITES;i++)
    {
        simulerOrbite(
        flotte[i]);
    }

    /* Détection collisions */

    printf(
    "\n\n===== ANALYSE DES DISTANCES =====\n");

    for(i=0;i<NB_SATELLITES;i++)
    {
        for(j=i+1;
            j<NB_SATELLITES;
            j++)
        {
            double d =
            distanceSatellites(
            flotte[i],
            flotte[j]);

            printf(
            "%s - %s : %.0f km\n",
            flotte[i].nom,
            flotte[j].nom,
            d/1000);

            if(d < 50000)
            {
                printf(
                "ALERTE COLLISION !\n");
            }

            printf("\n");
        }
    }

    return 0;
}
