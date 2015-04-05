#include "boardless_simulation.h"

boardless_simulation_states sim_state = sim_idle_state;

void handle_simulation_state() {
    switch(sim_state) {
    case anomaly_detected:
        sim_state = anomaly_detected_a;
        break;

    case anomaly_detected_a:
        sim_state = anomaly_detected_b;
        break;

    case anomaly_detected_b:
        sim_state = anomaly_removed_driving;
        break;

    case anomaly_removed_driving:
        sim_state = anomaly_removed_driving_a;
        break;

    case anomaly_removed_driving_a:
        sim_state = anomaly_removed_driving_b;
        break;

    case anomaly_removed_driving_b:
        sim_state = sim_idle_state;
        break;

    case sim_idle_state:
        sim_state = sim_idle_state_a;
        break;

    case sim_idle_state_a:
        sim_state = sim_idle_state_b;
        break;

    case sim_idle_state_b:
        sim_state = post_sim_idle_state_driving;
        break;

    case post_sim_idle_state_driving:
        sim_state = post_sim_idle_state_driving_a;
        break;

    case post_sim_idle_state_driving_a:
        sim_state = post_sim_idle_state_driving_b;
        break;

    case post_sim_idle_state_driving_b:
        sim_state = anomaly_detected;
        break;

    default:
        sim_state = sim_idle_state;
    };
}

