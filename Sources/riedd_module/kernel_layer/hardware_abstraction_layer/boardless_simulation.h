#ifndef BOARDLESS_SIMULATION_H
#define BOARDLESS_SIMULATION_H

typedef enum {
    anomaly_detected,
    anomaly_detected_a,
    anomaly_detected_b,

    sim_idle_state,
    sim_idle_state_a,
    sim_idle_state_b,

    anomaly_removed_driving,
    anomaly_removed_driving_a,
    anomaly_removed_driving_b,

    post_sim_idle_state_driving,
    post_sim_idle_state_driving_a,
    post_sim_idle_state_driving_b
} boardless_simulation_states;

extern boardless_simulation_states sim_state;
extern char slow_drive;
void handle_simulation_state();

#endif
