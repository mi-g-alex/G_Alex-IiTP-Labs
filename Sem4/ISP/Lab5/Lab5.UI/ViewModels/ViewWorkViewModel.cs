using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Lab5.Application.BrigadeUseCases.Commands;
using Lab5.Application.WorkUseCases.Commands;
using Lab5.Application.WorkUseCases.Queries;
using Lab5.Domain.Entities;
using Lab5.UI.Pages.TaskPages;
using MediatR;

namespace Lab5.UI.ViewModels;

[QueryProperty("Work", "Work")]
public partial class ViewWorkViewModel(IMediator mediator) : ObservableObject
{
    [ObservableProperty] private Work work;

    [ObservableProperty] private string name;
    [ObservableProperty] private int rating;
    [ObservableProperty] private DateTime startDate;
    [ObservableProperty] private DateTime endDate;
    [ObservableProperty] private string imageSrc;

    [RelayCommand]
    async Task GetWorkById()
    {
        Work = await mediator.Send(new GetWorkByIdQuery(Work.Id));
        Name = Work.Name;
        Rating = Work.Rating;
        StartDate = Work.StartDate;
        EndDate = Work.EndDate;
        ImageSrc = Work.ImageSrc;
    }


    [RelayCommand]
    async Task DeleteWork()
    {
        await mediator.Send(new DeleteWorkCommand(Work));
        await Shell.Current.GoToAsync("..");
    }

    [RelayCommand]
    private async Task EditWork()
    {
        await GotoAddOrEditPage(nameof(AddOrEditWork), new EditWorkCommand { Work = Work });
    }

    private async Task GotoAddOrEditPage(string route, IRequest request)
    {
        IDictionary<string, object> parameters =
            new Dictionary<string, object>()
            {
                { "Request", request },
                { "Work", Work }
            };
        await Shell.Current.GoToAsync(route, parameters);
    }
}