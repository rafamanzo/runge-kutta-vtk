#include <cstdlib>

#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <CImg.h>

#include <AnalyzeReader.h>

using namespace RungeKutta;
using namespace cimg_library;

vtkSmartPointer<vtkImageData> AnalyzeReader::readImage(char *file_name){
  int i, j, k, l;

  CImg<float> img(file_name);

  vtkSmartPointer<vtkImageData> vector_field = vtkSmartPointer<vtkImageData>::New();

  vector_field->SetDimensions(img.width(), img.height(), img.depth());
  vector_field->SetSpacing(1.0, 1.0, 1.0);
  vector_field->SetNumberOfScalarComponents(img.spectrum());
  vector_field->AllocateScalars();

  for (int i = 0; i < img.width(); i++)
    for (int j = 0; j < img.height(); j++)
      for (int k = 0; k < img.depth(); k++)
        for (int l = 0; l < img.spectrum(); l++)
          vector_field->SetScalarComponentFromDouble(i, j, k, l, img(i, j, k, l));

  vector_field->Update();

  return vector_field;
}