namespace Lab5.Application.WorkUseCases.Commands;

public class AddWorkHandler(IUnitOfWork unitOfWork) : IRequestHandler<AddWorkCommand>
{
    public async Task Handle(AddWorkCommand request, CancellationToken cancellationToken)
    {
        await unitOfWork.WorkRepository.AddAsync(request.Work, cancellationToken);
        await unitOfWork.SaveAllAsync();
    }
}