##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=med_device_sim
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=z:/verilog_sim
ProjectPath            :=z:/med_device_sim/med_device_sim
IntermediateDirectory  :=../../verilog_sim/build-$(WorkspaceConfiguration)/__/med_device_sim/med_device_sim
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=alan
Date                   :=7/22/2025
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=z:/verilog_sim/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\..\verilog_sim\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)emu 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/msys64/mingw64/bin/ar.exe -r
CXX      := C:/msys64/mingw64/bin/g++.exe
CC       := C:/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -O0 -gdwarf-2 -Wall -fcoroutines $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/monitor_controller_task.cpp$(ObjectSuffix) $(IntermediateDirectory)/sensor_data.cpp$(ObjectSuffix) $(IntermediateDirectory)/emu_sim_rtos.cpp$(ObjectSuffix) $(IntermediateDirectory)/emu_hw_sim.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/emu_phy_sim_task.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/monitor_controller_task.cpp$(ObjectSuffix): monitor_controller_task.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "z:/med_device_sim/med_device_sim/monitor_controller_task.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/monitor_controller_task.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/monitor_controller_task.cpp$(PreprocessSuffix): monitor_controller_task.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/monitor_controller_task.cpp$(PreprocessSuffix) monitor_controller_task.cpp

$(IntermediateDirectory)/sensor_data.cpp$(ObjectSuffix): sensor_data.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "z:/med_device_sim/med_device_sim/sensor_data.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sensor_data.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sensor_data.cpp$(PreprocessSuffix): sensor_data.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sensor_data.cpp$(PreprocessSuffix) sensor_data.cpp

$(IntermediateDirectory)/emu_sim_rtos.cpp$(ObjectSuffix): emu/sim_rtos.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "z:/med_device_sim/med_device_sim/emu/sim_rtos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/emu_sim_rtos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/emu_sim_rtos.cpp$(PreprocessSuffix): emu/sim_rtos.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/emu_sim_rtos.cpp$(PreprocessSuffix) emu/sim_rtos.cpp

$(IntermediateDirectory)/emu_hw_sim.cpp$(ObjectSuffix): emu/hw_sim.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "z:/med_device_sim/med_device_sim/emu/hw_sim.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/emu_hw_sim.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/emu_hw_sim.cpp$(PreprocessSuffix): emu/hw_sim.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/emu_hw_sim.cpp$(PreprocessSuffix) emu/hw_sim.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "z:/med_device_sim/med_device_sim/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/emu_phy_sim_task.cpp$(ObjectSuffix): emu/phy_sim_task.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "z:/med_device_sim/med_device_sim/emu/phy_sim_task.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/emu_phy_sim_task.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/emu_phy_sim_task.cpp$(PreprocessSuffix): emu/phy_sim_task.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/emu_phy_sim_task.cpp$(PreprocessSuffix) emu/phy_sim_task.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


