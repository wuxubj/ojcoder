class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        maxlen = 0
        pathlen = {0:0}
        for line in input.split('\n'):
            name = line.lstrip('\t')
            depth = len(line) - len(name)
            if '.' in name:
                maxlen = max(maxlen, len(name) + pathlen[depth])
            else:
                pathlen[depth + 1] = pathlen[depth] + len(name) + 1
                
        return maxlen