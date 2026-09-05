#include "movie_scheduler.h"

#include <cstdlib>
#include <optional>


namespace {

void Expect(MovieFrameAction actual, MovieFrameAction expected)
{
	if (actual != expected) {
		std::exit(EXIT_FAILURE);
	}
}

} // namespace


int main(void)
{
	Expect(Select_Movie_Frame(0.9, 1.0, 2.0), MovieFrameAction::Wait);
	Expect(Select_Movie_Frame(1.0, 1.0, 2.0), MovieFrameAction::Present);
	Expect(Select_Movie_Frame(2.0, 1.0, 2.0), MovieFrameAction::Drop);
	Expect(Select_Movie_Frame(1.999, 1.0, 2.0), MovieFrameAction::Present);
	Expect(Select_Movie_Frame(0.0, 1.0, std::nullopt), MovieFrameAction::Wait);
	Expect(Select_Movie_Frame(5.0, 4.0, std::nullopt), MovieFrameAction::Present);
	return(EXIT_SUCCESS);
}
