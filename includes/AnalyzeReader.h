namespace RungeKutta{
  class AnalyzeReader{
    public:
      static vtkSmartPointer<vtkImageData> readImage(char *file_name);
  };
}