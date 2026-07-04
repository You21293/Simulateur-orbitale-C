#include <math.h>
#include <stdio.h>

#define G 6.67430e-11
#define MASSE_TERRE 5.972e24
#define RAYON_TERRE 6371000
#define NB_SATELLITES 4

typedef struct {
    char nom[50];
    double altitude; // m
    double masse;    // kg
    double angle;    // degrés

    double vitesse; // m/s
    double periode; // s

} Satellite;

/* ========================= */
/* CALCULS PHYSIQUES */
/* ========================= */

double calculVitesse(double altitude) {
    double r = RAYON_TERRE + altitude;

    return sqrt((G * MASSE_TERRE) / r);
}

double calculPeriode(double altitude) {
    double r = RAYON_TERRE + altitude;

    return (2 * M_PI * r) / calculVitesse(altitude);
}

/* ========================= */
/* INITIALISATION */
/* ========================= */

void initialiserSatellite(Satellite *sat, char nom[], double altitude,
                          double masse, double angle) {
    int i = 0;

    while (nom[i] != '\0') {
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
/* SAISIE UTILISATEUR */
/* ========================= */

void saisirSatellite(Satellite *sat) {
    char nom[50];
    double altitude;
    double masse;
    double angle;

    printf("\nNom du satellite : ");
    scanf("%s", nom);

    printf("Altitude (km) : ");
    scanf("%lf", &altitude);

    printf("Masse (kg) : ");
    scanf("%lf", &masse);

    printf("Angle initial (0-360°) : ");
    scanf("%lf", &angle);

    initialiserSatellite(sat, nom, altitude * 1000.0, masse, angle);
}

/* ========================= */
/* AFFICHAGE */
/* ========================= */

void afficherSatellite(Satellite sat) {
    printf("\n=============================\n");

    printf("Satellite : %s\n", sat.nom);

    printf("Altitude : %.0f km\n", sat.altitude / 1000);

    printf("Masse : %.2f kg\n", sat.masse);

    printf("Vitesse : %.2f m/s\n", sat.vitesse);

    printf("Periode : %.2f min\n", sat.periode / 60.0);
}

/* ========================= */
/* SIMULATION */
/* ========================= */

void simulerOrbite(Satellite sat) {
    int temps;

    printf("\n--- Simulation %s ---\n", sat.nom);

    for (temps = 0; temps <= 3600; temps += 600) {
        double angle = fmod((360.0 * temps) / sat.periode, 360.0);

        printf("Temps : %4d s | Angle : %.2f degres\n", temps, angle);
    }
}

/* ========================= */
/* DISTANCE */
/* ========================= */

double distanceSatellites(Satellite s1, Satellite s2) {
    double r1 = RAYON_TERRE + s1.altitude;

    double r2 = RAYON_TERRE + s2.altitude;

    double x1 = r1 * cos(s1.angle * M_PI / 180.0);

    double y1 = r1 * sin(s1.angle * M_PI / 180.0);

    double x2 = r2 * cos(s2.angle * M_PI / 180.0);

    double y2 = r2 * sin(s2.angle * M_PI / 180.0);

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/* ========================= */
/* PROGRAMME PRINCIPAL */
/* ========================= */

int main() {
    Satellite flotte[NB_SATELLITES];

    printf("===================================\n");
    printf(" SIMULATEUR D'ORBITE DE SATELLITES\n");
    printf("===================================\n");

    /* Saisie des satellites */

    int i;
    int j;

    for (i = 0; i < NB_SATELLITES; i++) {
        printf("\n===== SATELLITE %d =====\n", i + 1);

        saisirSatellite(&flotte[i]);
    }

    /* Affichage */

    printf("\n\n===== DONNEES =====\n");

    for (i = 0; i < NB_SATELLITES; i++) {
        afficherSatellite(flotte[i]);
    }

    /* Simulation */

    printf("\n\n===== SIMULATION =====\n");

    for (i = 0; i < NB_SATELLITES; i++) {
        simulerOrbite(flotte[i]);
    }

    /* Analyse des distances */

    printf("\n\n===== ANALYSE DES DISTANCES =====\n");

    for (i = 0; i < NB_SATELLITES; i++) {
        for (j = i + 1; j < NB_SATELLITES; j++) {
            double d = distanceSatellites(flotte[i], flotte[j]);

            printf("%s - %s : %.0f km\n", flotte[i].nom, flotte[j].nom,
                   d / 1000);

            if (d < 50000) {
                printf("ALERTE COLLISION !\n");
            }

            printf("\n");
        }
    }

    return 0;
}
