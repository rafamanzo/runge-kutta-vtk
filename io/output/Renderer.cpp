#include <cstdio>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>

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

void Renderer::renderVectorField(){}

void Renderer::render(){
  renderRK2Fibers();
  renderRK4Fibers();
  renderVectorField();

  _renderWindow->Render();
  _renderWindowInteractor->Start();
}