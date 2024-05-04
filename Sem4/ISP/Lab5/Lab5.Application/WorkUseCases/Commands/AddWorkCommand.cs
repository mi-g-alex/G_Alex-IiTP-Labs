namespace Lab5.Application.WorkUseCases.Commands;

public sealed class AddWorkCommand : IAddOrEditWorkRequest
{
    public Work Work { get; set; }
}