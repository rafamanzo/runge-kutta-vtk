namespace RungeKutta{
  class Renderer{
    private:
      vtkSmartPointer<vtkRenderer> _renderer;
      vtkSmartPointer<vtkRenderWindow> _renderWindow;
      vtkSmartPointer<vtkRenderWindowInteractor> _renderWindowInteractor;
      vtkSmartPointer<vtkDataObject> _vector_field;
      vtkSmartPointer<vtkPolyData> _rk2_fibers;
      vtkSmartPointer<vtkPolyData> _rk4_fibers;

      void renderRK2Fibers();
      void renderRK4Fibers();
      void renderVectorField();
    public:
      Renderer(vtkSmartPointer<vtkDataObject> vector_field, vtkSmartPointer<vtkPolyData> rk2_fibers, vtkSmartPointer<vtkPolyData> rk4_fibers);
      void render();
  };
}