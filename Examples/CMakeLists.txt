cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
if(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW) # CMake 3.0
endif()
if(POLICY CMP0053)
  cmake_policy(SET CMP0053 NEW) # CMake 3.1
endif()

PROJECT(VTKExamples)
include_regular_expression("^.*$")

if(NOT VTK_BINARY_DIR)
  find_package(VTK REQUIRED)
else()
  set(VTK_DIR ${VTK_BINARY_DIR})
  find_package(VTK REQUIRED)
endif()

if (NOT vtkRenderingCore_LOADED)
  message(STATUS "vtkRenderingCore not found. No examples will be built")
else()
  add_subdirectory(AMR/Cxx)
  add_subdirectory(Annotation/Cxx/LabeledMesh)
  add_subdirectory(DataManipulation/Cxx)
  add_subdirectory(ImageProcessing/Cxx)
  add_subdirectory(IO/Cxx)
  add_subdirectory(LIC/Cxx)
  add_subdirectory(Medical/Cxx)
  add_subdirectory(Modelling/Cxx)
  add_subdirectory(MultiBlock/Cxx)
  add_subdirectory(Rendering/Cxx)
  add_subdirectory(Tutorial/Step1/Cxx)
  add_subdirectory(Tutorial/Step2/Cxx)
  add_subdirectory(Tutorial/Step3/Cxx)
  add_subdirectory(Tutorial/Step4/Cxx)
  add_subdirectory(Tutorial/Step5/Cxx)
  add_subdirectory(Tutorial/Step6/Cxx)
  add_subdirectory(VisualizationAlgorithms/Cxx)
  add_subdirectory(VolumeRendering/Cxx)
  add_subdirectory(Widgets/Cxx)
  # This may have been already built as part of the VTK build.
  # If so we cannot create the target "vtkLocalExample" because
  # an imported target of the same name already exists in the
  # VTK build.
  if(NOT vtkLocalExample_LOADED)
    add_subdirectory(Build/vtkLocal)
  endif()
  if(TARGET vtkGUISupportQt)
    add_subdirectory(GUI/Qt)
  endif()

#  add_subdirectory(Build/vtkMy)
#  add_subdirectory(GUI/Motif)
#  IF(VTK_USE_PARALLEL)
#   add_subdirectory(ParallelProcessing)
#  ENDIF(VTK_USE_PARALLEL)
#
#  IF(VTK_USE_INFOVIS)
#    IF(VTK_USE_CHARTS)
#      add_subdirectory(Charts/Cxx)
#    ENDIF(VTK_USE_CHARTS)
#    add_subdirectory(Infovis/Cxx)
#    IF(VTK_USE_N_WAY_ARRAYS)
#      add_subdirectory(Array/Cxx)
#    ENDIF(VTK_USE_N_WAY_ARRAYS)
#  ENDIF(VTK_USE_INFOVIS)
#   IF(VTK_USE_QVTK)
#    add_subdirectory(GUI/Qt)
#  ENDIF(VTK_USE_QVTK)
#   IF(WIN32)
#    add_subdirectory(GUI/Win32/SimpleCxx)
#     IF(VTK_USE_MFC)
#      add_subdirectory(GUI/Win32/SampleMFC)
#      add_subdirectory(GUI/Win32/vtkMFC)
#    ENDIF(VTK_USE_MFC)
#  ENDIF(WIN32)
endif()
