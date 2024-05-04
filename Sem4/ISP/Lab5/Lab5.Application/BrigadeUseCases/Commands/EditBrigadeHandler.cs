namespace Lab5.Application.BrigadeUseCases.Commands;

public class EditBrigadeHandler(IUnitOfWork unitOfWork) : IRequestHandler<EditBrigadeCommand>
{
    public async Task Handle(EditBrigadeCommand request, CancellationToken cancellationToken)
    {
        await unitOfWork.BrigadeRepository.UpdateAsync(request.Brigade, cancellationToken);
        await unitOfWork.SaveAllAsync();
    }
}