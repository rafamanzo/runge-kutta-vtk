namespace RungeKutta{
  class Tracer{
    private:
      vtkSmartPointer<vtkGenericStreamTracer> _stream_tracer;
    public:
      Tracer(vtkSmartPointer<vtkImageData> vector_field, vtkSmartPointer<vtkPolyData> initial_points, double step);
      vtkSmartPointer<vtkPolyData> trace(int type);
  };
}