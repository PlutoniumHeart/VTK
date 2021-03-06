vtk_module(vtkIOXML
  GROUPS
    StandAlone
  DEPENDS
    vtkIOXMLParser
    vtkIOGeometry
    vtkFiltersAMR
  PRIVATE_DEPENDS
    vtksys
  TEST_DEPENDS
    vtkFiltersAMR
    vtkFiltersCore
    vtkFiltersHyperTree
    vtkFiltersSources
    vtkImagingSources
    vtkInfovisCore
    vtkIOLegacy
    vtkRendering${VTK_RENDERING_BACKEND}
    vtkTestingCore
    vtkTestingRendering
    vtkInteractionStyle
    vtkIOParallelXML
  )
