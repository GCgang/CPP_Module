template <typename IT>
void Span::AddRange(IT begin, IT end)
{
	std::ptrdiff_t distance = std::distance(begin, end);

	if ((mVector.size() + static_cast<std::size_t>(distance)) > mSize)
	{
		throw Span::RangeOverflowException();
	}

	mVector.insert(mVector.end(), begin, end);
}