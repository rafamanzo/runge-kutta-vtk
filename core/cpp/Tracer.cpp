#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkPolyData.h>
#include <vtkAssignAttribute.h>
#include <vtkGenericStreamTracer.h>

#include <Tracer.h>

using namespace RungeKutta;

Tracer::Tracer(vtkSmartPointer<vtkImageData> vector_field, vtkSmartPointer<vtkPolyData> initial_points, double step){
  vtkSmartPointer<vtkAssignAttribute> vector_field_attribute = vtkSmartPointer<vtkAssignAttribute>::New();

  _stream_tracer = vtkSmartPointer<vtkGenericStreamTracer>::New();

  //generates vector_field_attribute
  vector_field_attribute->SetInput(vector_field);
  vector_field_attribute->Assign("vector_field", vtkDataSetAttributes::VECTORS, vtkAssignAttribute::POINT_DATA);

  _stream_tracer->SetSource(initial_points);
  _stream_tracer->SetInput(vector_field_attribute->GetOutput());
  _stream_tracer->SetInitialIntegrationStep(vtkGenericStreamTracer::LENGTH_UNIT, step);
}

vtkSmartPointer<vtkPolyData> Tracer::trace(int type){
  _stream_tracer->SetIntegratorType(type);

  _stream_tracer->Update();

  return _stream_tracer->GetOutput();
}