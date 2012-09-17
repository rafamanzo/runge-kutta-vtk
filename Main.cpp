#include <cstdlib>
#include <cstdio>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkImageData.h>
#include <vtkDataSetAttributes.h>
#include <vtkGenericStreamTracer.h>

#include <Input.h>
#include <Tracer.h>
#include <Renderer.h>

using namespace RungeKutta;

int main(int argc, char *argv[]){
  double h;
  vtkSmartPointer<vtkPolyData> initial_point_set = vtkSmartPointer<vtkPolyData>::New();
  vtkSmartPointer<vtkImageData> vector_field = vtkSmartPointer<vtkImageData>::New();
  Input file;
  Renderer renderer;

  //if(argc <= 2 && strcmp(argv[1], "--analyze") != 0){
  //  file = Input(argv[1], Input::NATIVE_TYPE);
  //}else{
    file = Input(argv[2], Input::ANALYZE_TYPE);
  //}

  file.parse(&h, initial_point_set, vector_field);

  Tracer tracer(vector_field, initial_point_set, h);
  vtkSmartPointer<vtkPolyData> fibers_rk2 = tracer.trace(vtkGenericStreamTracer::RUNGE_KUTTA2);

  renderer.render(fibers_rk2);
}