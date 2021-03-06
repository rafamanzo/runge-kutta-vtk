namespace RungeKutta{
  class Tracer{
    private:
      vtkSmartPointer<vtkStreamLine> _stream_line;
    public:
      Tracer(vtkSmartPointer<vtkDataObject> vector_field, vtkSmartPointer<vtkPolyData> initial_points, double step);
      vtkSmartPointer<vtkPolyData> trace(vtkSmartPointer<vtkInitialValueProblemSolver> integrator);
  };
}