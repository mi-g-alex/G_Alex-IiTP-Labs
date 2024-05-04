namespace Lab5.Application.WorkUseCases.Commands;

public class DeleteWorkHandler(IUnitOfWork unitOfWork) : IRequestHandler<DeleteWorkCommand>
{
    public async Task Handle(DeleteWorkCommand request, CancellationToken cancellationToken)
    {
        await unitOfWork.WorkRepository.DeleteAsync(request.Work);
        await unitOfWork.SaveAllAsync();
    }
}