import sys


def score_analytics():
    arguments = sys.argv[1:]
    scores = []

    print("=== Player Score Analytics ===")

    if len(arguments) == 0:
        print(
            "No scores provided. "
            "Usage: python3 ft_score_analytics.py <score1> <score2> ..."
            )
    else:
        for arg in arguments:
            try:
                scores = scores + [int(arg)]
            except ValueError:
                print("Invalid input '" + arg + "': Not a number.")
                
    if len(scores) > 0:
        total_players = len(scores)
        total_score = sum(scores)
        average_score = total_score / total_players
        highest_score = max(scores)
        lowest_score = min(scores)
        score_range = highest_score - lowest_score

        print("Scores processed:", scores)
        print("Total players:", total_players)
        print("Total score:", total_score)
        print("Average score:", average_score)
        print("High score:", highest_score)
        print("Low score:", lowest_score)
        print("Score range:", score_range)


if __name__ == "__main__":
    score_analytics()
