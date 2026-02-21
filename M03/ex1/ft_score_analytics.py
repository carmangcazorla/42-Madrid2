import sys

arguments = sys.argv[1:]
if len(sys.origin_argv):
    print("No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...")
    return
else:
