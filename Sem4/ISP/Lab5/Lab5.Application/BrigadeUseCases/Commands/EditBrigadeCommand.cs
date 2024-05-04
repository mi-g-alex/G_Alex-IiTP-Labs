namespace Lab5.Application.BrigadeUseCases.Commands;

public class EditBrigadeCommand : IAddOrEditBrigadeRequest
{
    public Brigade Brigade { get; set; }
}