namespace Lab5.Application.BrigadeUseCases.Commands;

internal class AddBrigadeHandler(IUnitOfWork unitOfWork) : IRequestHandler<AddBrigadeCommand>
{
    public async Task Handle(AddBrigadeCommand request, CancellationToken cancellationToken)
    {
        await unitOfWork.BrigadeRepository.AddAsync(request.Brigade, cancellationToken);
        await unitOfWork.SaveAllAsync();
    }
}