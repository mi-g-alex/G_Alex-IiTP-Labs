namespace Lab5.Application.WorkUseCases.Queries;

internal class GetWorkByIdQueryHandler(IUnitOfWork unitOfWork)
    : IRequestHandler<GetWorkByIdQuery, Work>
{
    public async Task<Work> Handle(GetWorkByIdQuery request, CancellationToken cancellationToken)
    {
        return await unitOfWork.WorkRepository.FirstOrDefaultAsync(s => s.Id == request.Id, cancellationToken);
    }
}