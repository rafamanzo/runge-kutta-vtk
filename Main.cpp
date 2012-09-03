#include <cstdlib>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkImageData.h>

#include <Input.h>

using namespace RungeKutta;

int main(int argc, char *argv[]){
  double h;
  vtkSmartPointer<vtkPolyData> initial_point_set = vtkSmartPointer<vtkPolyData>::New();
  vtkSmartPointer<vtkImageData> vector_field = vtkSmartPointer<vtkImageData>::New();
  Input file;

  //if(argc <= 2 && strcmp(argv[1], "--analyze") != 0){
  //  file = Input(argv[1], Input::NATIVE_TYPE);
  //}else{
    file = Input(argv[2], Input::ANALYZE_TYPE);
  //}
  file.parse(&h, initial_point_set, vector_field);
}