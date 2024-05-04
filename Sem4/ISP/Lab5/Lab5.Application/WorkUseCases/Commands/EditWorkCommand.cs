namespace Lab5.Application.WorkUseCases.Commands;

public class EditWorkCommand : IAddOrEditWorkRequest
{
    public Work Work { get; set; }
}