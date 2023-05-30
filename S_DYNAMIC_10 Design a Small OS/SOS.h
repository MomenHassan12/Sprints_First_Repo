/*
 * SOS.h
 *
 * Created: 5/30/2023 3:15:57 AM
 *  Author: Speed
 */ 


#ifndef SOS_H_
#define SOS_H_



// Enumeration for system status
typedef enum {
	SOS_STATUS_SUCCESS,
	SOS_STATUS_INVALID_STATE
} enu_system_status_t;

// Task structure
typedef struct {
    uint8_t u8_taskID;
   uint8_t  u8_priority;              // Task priority to every task
    uint32_t u32_intervalMs;          // Task execution interval in milliseconds
    uint32_t u32_executionTimeMs;     // Execution time of the task in milliseconds
} sos_task_t;

// Function prototypes
enu_system_status_t sos_init(void);
enu_system_status_t sos_deinit(void);
enu_system_status_t sos_create_task(sos_task_t * ptr_sos_task);
enu_system_status_t sos_delete_task(uint8_t u8_task_ID);
enu_system_status_t sos_modify_task(uint8_t u8_task_ID,sos_task_t * ptr_sos_task);
void sos_disable(void);
void sos_run(void);


#endif /* SOS_H_ */