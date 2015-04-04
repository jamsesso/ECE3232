#ifndef DRIVE_H
#define DRIVE_H

typedef struct driver_struct {
	/**
	 * Starts driving the wheels at full power
	 */
	void (*start_driving) (struct driver_struct*);

	/**
	 * Stops driving the wheels
	 */
	void (*stop_driving) (struct driver_struct*);
} driver_t;

/**
 * Creates and returns a driver module singleton
 */
driver_t* get_driver();

#endif /* DRIVE_H_ */
