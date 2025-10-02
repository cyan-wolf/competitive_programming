"""
Given a set of activities, each with a start and finish time, select the maximum number of non-overlapping activities.
"""

from dataclasses import dataclass

@dataclass
class Activity:
    start: int
    finish: int
    name: str


# O(n log n)
def main():
    activities = [
        Activity(0, 4, 'A'),
        Activity(0, 1, 'B'),
        Activity(1, 3, 'C'),
        Activity(3, 4, 'D'),
        Activity(4, 6, 'E'),
        Activity(1, 9, 'F'),
        Activity(8, 9, 'G'),
    ]

    # O(n log n)
    activities.sort(key=lambda a: a.finish)

    picked_activitities = []

    most_recent_finish = float('-inf')

    # O(n)
    for activity in activities:
        if activity.start >= most_recent_finish:
            picked_activitities.append(activity)
            most_recent_finish = activity.finish

    print(picked_activitities)


if __name__ == "__main__":
    main()

