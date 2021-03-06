#include <cstdio>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkGlyph3D.h>
#include <vtkArrowSource.h>
#include <vtkProperty.h>

#include <Renderer.h>

using namespace RungeKutta;

Renderer::Renderer(vtkSmartPointer<vtkDataObject> vector_field, vtkSmartPointer<vtkPolyData> rk2_fibers, vtkSmartPointer<vtkPolyData> rk4_fibers){
  _renderer = vtkSmartPointer<vtkRenderer>::New();
  _renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  _renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  _renderWindow->AddRenderer(_renderer);
  _renderWindowInteractor->SetRenderWindow(_renderWindow);

  _vector_field = vector_field;
  _rk2_fibers = rk2_fibers;
  _rk4_fibers = rk4_fibers;
}

void Renderer::renderRK2Fibers(){
  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

  mapper->SetInput(_rk2_fibers);
  actor->SetMapper(mapper);

  _renderer->AddActor(actor);
}

void Renderer::renderRK4Fibers(){
  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

  mapper->SetInput(_rk4_fibers);
  actor->SetMapper(mapper);

  _renderer->AddActor(actor);
}

void Renderer::renderVectorField(){
  vtkSmartPointer<vtkArrowSource> shape = vtkSmartPointer<vtkArrowSource>::New();
  vtkSmartPointer<vtkGlyph3D> vector_field = vtkSmartPointer<vtkGlyph3D>::New();
  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();


  vector_field->SetInput(_vector_field);
  vector_field->SetSource(shape->GetOutput());
  vector_field->SetScaleModeToScaleByVector();
  vector_field->SetScaleFactor(0.1);
  vector_field->Update();

  mapper->SetInput(vector_field->GetOutput());
  mapper->ScalarVisibilityOff();
  actor->SetMapper(mapper);
  property = actor->GetProperty();
  property->SetColor(0.5,0.5,0.5);
  actor->SetProperty(property);

  _renderer->AddActor(actor);
}

void Renderer::render(){
  renderRK2Fibers();
  renderRK4Fibers();
  renderVectorField();

  _renderWindow->Render();
  _renderWindowInteractor->Start();
}