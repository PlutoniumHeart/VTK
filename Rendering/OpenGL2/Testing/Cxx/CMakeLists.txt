vtk_add_test_cxx(${vtk-module}CxxTests tests
  #TestRenderWidget.cxx # Very experimental, fails, does nothing useful yet.
  TestVBOPLYMapper.cxx
  TestVBOPointsLines.cxx
  )

vtk_test_cxx_executable(${vtk-module}CxxTests tests RENDERING_FACTORY)
