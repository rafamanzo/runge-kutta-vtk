#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkPolyData.h>
#include <vtkAssignAttribute.h>
#include <vtkInitialValueProblemSolver.h>
#include <vtkStreamLine.h>

#include <Tracer.h>

using namespace RungeKutta;

Tracer::Tracer(vtkSmartPointer<vtkImageData> vector_field, vtkSmartPointer<vtkPolyData> initial_points, double step){
  vtkSmartPointer<vtkAssignAttribute> vector_field_attribute = vtkSmartPointer<vtkAssignAttribute>::New();

  _stream_line = vtkSmartPointer<vtkStreamLine>::New();

  //generates vector_field_attribute
  vector_field_attribute->SetInput(vector_field);
  vector_field_attribute->Assign(vtkDataSetAttributes::SCALARS, vtkDataSetAttributes::VECTORS, vtkAssignAttribute::POINT_DATA);
  vector_field_attribute->Update();

  _stream_line->SetSource(initial_points);
  _stream_line->SetInput(vector_field_attribute->GetOutput());
  //_stream_line->SelectInputVectors("vector_field");
  _stream_line->SetStepLength(step);
}

vtkSmartPointer<vtkPolyData> Tracer::trace(vtkSmartPointer<vtkInitialValueProblemSolver> integrator){
  _stream_line->SetIntegrator(integrator);
  _stream_line->Update();

  return _stream_line->GetOutput();
}