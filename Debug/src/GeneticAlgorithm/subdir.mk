################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GeneticAlgorithm/GeneticAlgorithm.cpp \
../src/GeneticAlgorithm/Individual.cpp \
../src/GeneticAlgorithm/Population.cpp 

OBJS += \
./src/GeneticAlgorithm/GeneticAlgorithm.o \
./src/GeneticAlgorithm/Individual.o \
./src/GeneticAlgorithm/Population.o 

CPP_DEPS += \
./src/GeneticAlgorithm/GeneticAlgorithm.d \
./src/GeneticAlgorithm/Individual.d \
./src/GeneticAlgorithm/Population.d 


# Each subdirectory must supply rules for building sources it contributes
src/GeneticAlgorithm/%.o: ../src/GeneticAlgorithm/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


