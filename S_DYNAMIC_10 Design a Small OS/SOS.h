/*
 * SOS.h
 *
 * Created: 5/30/2023 3:15:57 AM
 *  Author: Speed
 */ 


#ifndef SOS_H_
#define SOS_H_


#include <stdint.h>

// Enumeration for system status
typedef enum {
	SOS_STATUS_SUCCESS,
	SOS_STATUS_INVALID_STATE
} enu_system_status_t;

// Task structure
typedef struct {
    uint8_t taskID;
    uint32_t intervalMs;          // Task execution interval in milliseconds
    uint32_t lastExecutionTime;   // Timestamp of the last task execution
    uint32_t executionTimeMs;     // Execution time of the task in milliseconds
    void (*taskFunction)(void);
} sos_task_t;

// Function prototypes
enu_system_status_t sos_init(void);
enu_system_status_t sos_deinit(void);
enu_system_status_t sos_create_task(uint32_t intervalMs, void (*taskFunction)(void), uint8_t* taskID);
enu_system_status_t sos_delete_task(uint8_t taskID);
enu_system_status_t sos_modify_task(uint8_t taskID, uint32_t intervalMs, void (*taskFunction)(void));
void sos_disable(void);
void sos_run(void);


#endif /* SOS_H_ */