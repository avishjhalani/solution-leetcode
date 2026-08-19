class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        mp = {}

        for reserve in reservedSeats:
            row = reserve[0]
            col = reserve[1]

            if row not in mp:
                mp[row] = set()

            mp[row].add(col)

        result = 0

        # rows with no reserved seats
        result += (n - len(mp)) * 2

        for row, book in mp.items():

            def isAvailable(seat):
                return seat not in book

            GroupA = (
                isAvailable(2) and
                isAvailable(3) and
                isAvailable(4) and
                isAvailable(5)
            )

            GroupB = (
                isAvailable(4) and
                isAvailable(5) and
                isAvailable(6) and
                isAvailable(7)
            )

            GroupC = (
                isAvailable(6) and
                isAvailable(7) and
                isAvailable(8) and
                isAvailable(9)
            )

            if GroupA and GroupC:
                result += 2
            elif GroupA or GroupB or GroupC:
                result += 1

        return result
        """
        :type n: int
        :type reservedSeats: List[List[int]]
        :rtype: int
        """
        