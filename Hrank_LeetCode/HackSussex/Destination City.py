def solution(paths: list[list[str]]) -> str:
    outs = set()
    ins = set()

    for a,b in paths:
        outs.add(a)
        ins.add(b)

    return next(city for city in ins if city not in outs)

def solution_(paths: list[list[str]]) -> str:
    outs = set()
    ins = set()

    for a, b in paths:
        outs.add(a)
        ins.add(b)

    for city in ins:
        if city not in outs:
            return city

def test_solution():
    assert solution([["London", "New York"], ["New York", "Lima"], ["Lima", "Sao Paulo"]]) == "Sao Paulo"
    assert solution([["A", "B"], ["B", "C"], ["C", "D"], ["D", "E"]]) == "E"
    assert solution([["City1", "City2"], ["City2", "City3"], ["City3", "City4"], ["City4", "City5"], ["City5", "City6"]]) == "City6"
    assert solution([["X", "Y"], ["Y", "Z"]]) == "Z"
    assert solution([["Start", "Middle"], ["Middle", "End"]]) == "End"
    assert solution([["Alpha", "Beta"], ["Beta", "Gamma"], ["Gamma", "Delta"]]) == "Delta"
    assert solution([["OnlyCityA", "OnlyCityB"]]) == "OnlyCityB"
    assert solution([["A", "B"], ["D", "E"], ["B", "C"], ["C", "D"]]) == "E"
    assert solution([["X", "Y"], ["Y", "X"], ["Y", "Z"]]) == "Z"

    print("All test cases passed!")

test_solution()
