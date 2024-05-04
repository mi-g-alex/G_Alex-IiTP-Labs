using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Lab5.Application.BrigadeUseCases.Commands;
using MediatR;

namespace Lab5.UI.ViewModels;

public partial class AddOrEditBrigadeViewModel(IMediator mediator) : ObservableObject, IQueryAttributable
{
    private IAddOrEditBrigadeRequest _request;

    [ObservableProperty] private string name;
    [ObservableProperty] private string companyName;
    [ObservableProperty] private string worksType;


    public void ApplyQueryAttributes(IDictionary<string, object> query)
    {
        _request = query["Request"] as IAddOrEditBrigadeRequest;
        if (_request == null) return;
        Name = _request.Brigade.Name;
        CompanyName = _request.Brigade.CompanyName;
        WorksType = _request.Brigade.WorksType;
    }

    [RelayCommand]
    async Task AddOrEditBrigade()
    {
        _request.Brigade.Name = Name;
        _request.Brigade.CompanyName = CompanyName;
        _request.Brigade.WorksType = WorksType;
        await mediator.Send(_request);
        await GoBack();
    }

    [RelayCommand]
    async Task GoBack()
    {
        await Shell.Current.GoToAsync("..");
    }
}