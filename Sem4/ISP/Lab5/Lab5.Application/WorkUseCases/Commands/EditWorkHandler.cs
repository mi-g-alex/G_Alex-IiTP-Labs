namespace Lab5.Application.WorkUseCases.Commands;

public class EditWorkHandler(IUnitOfWork unitOfWork) : IRequestHandler<EditWorkCommand>
{
    public async Task Handle(EditWorkCommand request, CancellationToken cancellationToken)
    {
        await unitOfWork.WorkRepository.UpdateAsync(request.Work, cancellationToken);
        await unitOfWork.SaveAllAsync();
    }
}