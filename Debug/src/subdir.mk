################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Hall\ Sensor.c \
../src/Input_Capture_Thread_entry.c \
../src/PWM_Thread_entry.c \
../src/Ram.c \
../src/Timing_Thread_entry.c \
../src/guiapp_event_handlers.c \
../src/hal_entry.c \
../src/main_thread_entry.c \
../src/sensor_thread_entry.c 

OBJS += \
./src/Hall\ Sensor.o \
./src/Input_Capture_Thread_entry.o \
./src/PWM_Thread_entry.o \
./src/Ram.o \
./src/Timing_Thread_entry.o \
./src/guiapp_event_handlers.o \
./src/hal_entry.o \
./src/main_thread_entry.o \
./src/sensor_thread_entry.o 

C_DEPS += \
./src/Hall\ Sensor.d \
./src/Input_Capture_Thread_entry.d \
./src/PWM_Thread_entry.d \
./src/Ram.d \
./src/Timing_Thread_entry.d \
./src/guiapp_event_handlers.d \
./src/hal_entry.d \
./src/main_thread_entry.d \
./src/sensor_thread_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/Hall\ Sensor.o: ../src/Hall\ Sensor.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\Synergy\e2studio_v6.2.1_ssp_v1.5.0\eclipse\../Utilities/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -DSF_MESSAGE_CLASS -I../GUIApp/synergy_cfg/ssp_cfg/bsp/ -I../GUIApp/synergy_cfg/ssp_cfg/driver/ -I../GUIApp/synergy/ssp/inc/ -I../GUIApp/synergy/ssp/inc/bsp/ -I../GUIApp/synergy/ssp/inc/bsp/cmsis/Include/ -I../GUIApp/synergy/ssp/inc/driver/api/ -I../GUIApp/synergy/ssp/inc/driver/instances/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/el/ -I../GUIApp/synergy/ssp/inc/framework/el/ -I../GUIApp/synergy/ssp/src/framework/el/tx/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/ -I../GUIApp/synergy/ssp/inc/framework/api/ -I../GUIApp/synergy/ssp/inc/framework/instances/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/tes/ -I../GUIApp/synergy/ssp/inc/framework/tes/ -I../GUIApp/synergy_cfg/framework/ -I../GUIApp/synergy_cfg/ssp_cfg/framework -I../GUIApp/synergy/ssp/inc/framework/api -I../GUIApp/synergy/ssp/inc/framework/instances -I../GUIApp/synergy_cfg/ssp_cfg/framework/tes -I../GUIApp/synergy/ssp/inc/framework/tes -I../GUIApp/synergy_cfg/ssp_cfg/framework/el -I../GUIApp/synergy/ssp/inc/framework/el -I../GUIApp/synergy/ssp/src/framework/el/tx -I../GUIApp/synergy_cfg/ssp_cfg/bsp -I../GUIApp/synergy_cfg/ssp_cfg/driver -I../GUIApp/synergy/ssp/inc -I../GUIApp/synergy/ssp/inc/bsp -I../GUIApp/synergy/ssp/inc/bsp/cmsis/Include -I../GUIApp/synergy/ssp/inc/driver/api -I../GUIApp/synergy/ssp/inc/driver/instances -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy_cfg\ssp_cfg\framework" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\framework\api" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\framework\instances" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\framework\tes" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy_cfg\ssp_cfg\framework\el" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\framework\el" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\src\framework\el\tx" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy_cfg\ssp_cfg\driver" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\bsp" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\driver\api" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\driver\instances" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\src" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\src\synergy_gen" -std=c99 -MMD -MP -MF"src/Hall Sensor.d" -MT"src/Hall\ Sensor.d" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\Synergy\e2studio_v6.2.1_ssp_v1.5.0\eclipse\../Utilities/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -DSF_MESSAGE_CLASS -I../GUIApp/synergy_cfg/ssp_cfg/bsp/ -I../GUIApp/synergy_cfg/ssp_cfg/driver/ -I../GUIApp/synergy/ssp/inc/ -I../GUIApp/synergy/ssp/inc/bsp/ -I../GUIApp/synergy/ssp/inc/bsp/cmsis/Include/ -I../GUIApp/synergy/ssp/inc/driver/api/ -I../GUIApp/synergy/ssp/inc/driver/instances/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/el/ -I../GUIApp/synergy/ssp/inc/framework/el/ -I../GUIApp/synergy/ssp/src/framework/el/tx/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/ -I../GUIApp/synergy/ssp/inc/framework/api/ -I../GUIApp/synergy/ssp/inc/framework/instances/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/tes/ -I../GUIApp/synergy/ssp/inc/framework/tes/ -I../GUIApp/synergy_cfg/framework/ -I../GUIApp/synergy_cfg/ssp_cfg/framework -I../GUIApp/synergy/ssp/inc/framework/api -I../GUIApp/synergy/ssp/inc/framework/instances -I../GUIApp/synergy_cfg/ssp_cfg/framework/tes -I../GUIApp/synergy/ssp/inc/framework/tes -I../GUIApp/synergy_cfg/ssp_cfg/framework/el -I../GUIApp/synergy/ssp/inc/framework/el -I../GUIApp/synergy/ssp/src/framework/el/tx -I../GUIApp/synergy_cfg/ssp_cfg/bsp -I../GUIApp/synergy_cfg/ssp_cfg/driver -I../GUIApp/synergy/ssp/inc -I../GUIApp/synergy/ssp/inc/bsp -I../GUIApp/synergy/ssp/inc/bsp/cmsis/Include -I../GUIApp/synergy/ssp/inc/driver/api -I../GUIApp/synergy/ssp/inc/driver/instances -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy_cfg\ssp_cfg\framework" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\framework\api" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\framework\instances" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\framework\tes" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy_cfg\ssp_cfg\framework\el" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\framework\el" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\src\framework\el\tx" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy_cfg\ssp_cfg\driver" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\bsp" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\driver\api" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\synergy\ssp\inc\driver\instances" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\src" -I"C:\Users\JHVMEXMM\e2_studio\workspace\DSE_Motor_Control_E7\src\synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


