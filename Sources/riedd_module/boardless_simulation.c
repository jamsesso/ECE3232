#include "boardless_simulation.h"
#include <stdio.h>

boardless_simulation_states sim_state = sim_idle_state;

void handle_simulation_state() {
    switch(sim_state) {
    case anomaly_detected:
        printf("anomaly_detected\n");
        sim_state = anomaly_detected_a;
        break;

    case anomaly_detected_a:
        printf("anomaly_detected_a\n");
        sim_state = anomaly_detected_b;
        break;

    case anomaly_detected_b:
        printf("anomaly_detected_b\n");
        sim_state = anomaly_removed_driving;
        break;

    case anomaly_removed_driving:
        printf("anomaly_removed_driving\n");
        sim_state = anomaly_removed_driving_a;
        break;

    case anomaly_removed_driving_a:
        printf("anomaly_removed_driving_a\n");
        sim_state = anomaly_removed_driving_b;
        break;

    case anomaly_removed_driving_b:
        printf("anomaly_removed_driving_b\n");
        sim_state = sim_idle_state;
        break;

    case sim_idle_state:
        printf("sim_idle_state\n");
        sim_state = sim_idle_state_a;
        break;

    case sim_idle_state_a:
        printf("sim_idle_state_a\n");
        sim_state = sim_idle_state_b;
        break;

    case sim_idle_state_b:
        printf("sim_idle_state_b\n");
        sim_state = post_sim_idle_state_driving;
        break;

    case post_sim_idle_state_driving:
        printf("post_sim_idle_state_driving\n");
        sim_state = post_sim_idle_state_driving_a;
        break;

    case post_sim_idle_state_driving_a:
        printf("post_sim_idle_state_driving_a\n");
        sim_state = post_sim_idle_state_driving_b;
        break;

    case post_sim_idle_state_driving_b:
        printf("post_sim_idle_state_driving_b\n");
        sim_state = anomaly_detected;
        break;

    default:
        printf("default\n");
        sim_state = sim_idle_state;
    };
}

