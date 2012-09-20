#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkImageData.h>

#include <AnalyzeReader.h>
#include <Input.h>

using namespace RungeKutta;

Input::Input(char *file_name, unsigned file_type){
  _file_name = (char *) malloc(strlen(file_name)*sizeof(char));
  strcpy(_file_name, file_name);
  _file_type = file_type;
}

Input::Input(){
  _file_name = NULL;
  _file_type = 2;
}

void Input::parse(double *h, vtkSmartPointer<vtkPolyData> *initial_point_set, vtkSmartPointer<vtkImageData> *vector_field){
  //if(_file_type == NATIVE_TYPE)
  //  return parseNative(h,v0,v0_count);
  //else if(_file_type == ANALYZE_TYPE)
  parseAnalyze(h, initial_point_set, vector_field);

  //return DataSet();
}

void Input::parseAnalyze(double *h, vtkSmartPointer<vtkPolyData> *initial_point_set, vtkSmartPointer<vtkImageData> *vector_field){
  unsigned initial_points_count, i;
  double v_x, v_y, v_z;

  vtkSmartPointer<vtkPoints> initial_points = vtkSmartPointer<vtkPoints>::New();

  printf("\nPlease enter the initial points count:\n");
  scanf("%u", &initial_points_count);
  for(i = 0; i < initial_points_count; i++){
    printf("\nPlease enter the %dth initial points coordinates:\n", i);
    scanf("%lf", &v_x);
    scanf("%lf", &v_y);
    scanf("%lf", &v_z);

    initial_points->InsertPoint(i, v_x, v_y, v_z);
  }
  (*initial_point_set)->SetPoints(initial_points);

  printf("\nPlease enter the step size:\n");
  scanf("%lf", h);

  (*vector_field) = AnalyzeReader::readImage(_file_name);
}