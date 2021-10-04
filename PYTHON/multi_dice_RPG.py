from random import choice


class Dice(object):

    def __init__(self) -> None:
        self.faces = [i for i in range(1,100)]


    def _run_dices(self, n_faces=6) -> int:
        return choice(self.faces[0:n_faces])

    
    def run(self, dices=[6], times=1) -> dict:
        results = {}
        for i in range(0, times):
            roll = []
            for j in dices:
                roll.append(self._run_dices(j))
            results.update({f'Round {i+1}': {'results':roll, 'total':sum(roll)}})
        return results
