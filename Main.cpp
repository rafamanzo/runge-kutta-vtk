#include <cstdlib>
#include <cstdio>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkDataObject.h>
#include <vtkDataSetAttributes.h>
#include <vtkRungeKutta2.h>
#include <vtkStreamLine.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>

#include <Input.h>
#include <Tracer.h>
#include <Renderer.h>

using namespace RungeKutta;

int main(int argc, char *argv[]){
  double h;
  vtkSmartPointer<vtkPolyData> initial_point_set = vtkSmartPointer<vtkPolyData>::New();
  vtkSmartPointer<vtkDataObject> vector_field = vtkSmartPointer<vtkDataObject>::New();
  vtkSmartPointer<vtkRungeKutta2> algorithm = vtkSmartPointer<vtkRungeKutta2>::New();
  Input file;

  //if(argc <= 2 && strcmp(argv[1], "--analyze") != 0){
  //  file = Input(argv[1], Input::NATIVE_TYPE);
  //}else{
    file = Input(argv[2], Input::ANALYZE_TYPE);
  //}

  file.parse(&h, &initial_point_set, &vector_field);

  Tracer tracer(vector_field, initial_point_set, h);
  vtkSmartPointer<vtkPolyData> fibers_rk2 = tracer.trace(algorithm);
  vtkSmartPointer<vtkPolyData> fibers_rk4 = tracer.trace(algorithm);

  Renderer renderer(vector_field, fibers_rk2, fibers_rk4);
  renderer.render();
}