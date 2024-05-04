using System.Collections.ObjectModel;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Lab5.Application.BrigadeUseCases.Commands;
using Lab5.Application.BrigadeUseCases.Queries;
using Lab5.Application.WorkUseCases.Commands;
using Lab5.Application.WorkUseCases.Queries;
using Lab5.Domain.Entities;
using Lab5.UI.Pages.TaskPages;
using MediatR;

namespace Lab5.UI.ViewModels;

public partial class ViewBrigadesViewModel(IMediator mediator) : ObservableObject
{
    [ObservableProperty] Brigade? selectedBrigade;

    public ObservableCollection<Brigade> ListOfBrigades { get; set; } = [];

    public ObservableCollection<Work> ListOfWorks { get; } = [];

    [RelayCommand]
    async Task LoadBrigades()
    {
        if (SelectedBrigade != null) return;
        await GetBrigades();
    }

    [RelayCommand]
    async Task UpdateSelectedBrigade(Brigade selected) => await GetWorks(selected);

    [RelayCommand]
    async Task UpdateWorks() => await GetWorks(SelectedBrigade);

    private async Task GetBrigades()
    {
        ListOfBrigades.Clear();
        ListOfWorks.Clear();
        var courses = await mediator.Send(new GetBrigadesQuery());
        foreach (var i in courses)
        {
            ListOfBrigades.Add(i);
        }
    }

    private async Task GetWorks(Brigade? selected)
    {
        ListOfWorks.Clear();
        if (selected != null)
        {
            var list = await mediator.Send(new GetWorksByBrigadeIdQuery(selected.Id));
            foreach (var work in list)
            {
                ListOfWorks.Add(work);
            }
        }
    }

    [RelayCommand]
    private async Task GoToWork(Work selectedWork) => await GoToWorkPage(selectedWork);

    private async Task GoToWorkPage(Work work)
    {
        IDictionary<string, object> parameters =
            new Dictionary<string, object>()
            {
                { "Work", work }
            };
        await Shell.Current
            .GoToAsync(nameof(ViewWork), parameters);
    }


    private async Task GotoAddOrEditPage(string route, IRequest request)
    {
        IDictionary<string, object> parameters =
            new Dictionary<string, object>()
            {
                { "Request", request }
            };
        await Shell.Current.GoToAsync(route, parameters);
    }

    [RelayCommand]
    private async Task AddWork()
    {
        if (SelectedBrigade != null)
        {
            await GotoAddOrEditPage(nameof(AddOrEditWork),
                new AddWorkCommand { Work = new Work { BrigadeId = SelectedBrigade.Id } });
            await GetWorks(SelectedBrigade);
        }
    }

    [RelayCommand]
    private async Task AddBrigade()
    {
        await GotoAddOrEditPage(nameof(AddOrEditBrigade), new AddBrigadeCommand() { Brigade = new Brigade() });
        await GetBrigades();
    }

    [RelayCommand]
    private async Task EditBrigade()
    {
        if (SelectedBrigade == null) return;
        await GotoAddOrEditPage(nameof(AddOrEditBrigade), new EditBrigadeCommand { Brigade = SelectedBrigade });
        await GetBrigades();
    }

    [RelayCommand]
    private async Task DeleteBrigade()
    {
        if (SelectedBrigade == null) return;
        await mediator.Send(new DeleteBrigadeCommand(SelectedBrigade));
        await GetBrigades();
    }
}