namespace RungeKutta{
  class Input{
    private:
      char *_file_name;
      unsigned _file_type;
      void parseAnalyze(double *h, vtkSmartPointer<vtkPolyData> *initial_point_set, vtkSmartPointer<vtkDataObject> *vector_field);
    public:
      static const unsigned NATIVE_TYPE = 0;
      static const unsigned ANALYZE_TYPE = 1;
      Input(char *file_name, unsigned file_type);
      Input();
      void parse(double *h, vtkSmartPointer<vtkPolyData> *initial_point_set, vtkSmartPointer<vtkDataObject> *vector_field);
  };
}