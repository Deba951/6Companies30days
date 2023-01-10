// https://leetcode.com/problems/perfect-rectangle/

class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        int blox = Integer.MAX_VALUE, bloy = Integer.MAX_VALUE, trix = Integer.MIN_VALUE, triy = Integer.MIN_VALUE;
        int area = 0;
        Set<String> points = new HashSet<String>();
        
        for (int i = 0; i < rectangles.length; i ++) {
            int[] rect = rectangles[i];
            blox = Math.min(blox, rect[0]);
            bloy = Math.min(bloy, rect[1]);
            trix = Math.max(trix, rect[2]);
            triy = Math.max(triy, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
        
            String[] ps = new String[4];
            ps[0] = rect[0] + "," + rect[1];
            ps[1] = rect[0] + "," + rect[3];
            ps[2] = rect[2] + "," + rect[1];
            ps[3] = rect[2] + "," + rect[3];
        
            for (int j = 0; j < ps.length; j ++){
                if (points.contains(ps[j]))
                    points.remove(ps[j]);
                
                else
                    points.add(ps[j]);
            }
        }
        
        String[] ps = new String[4];
        ps[0] = blox + "," + bloy;
        ps[1] = blox + "," + triy;
        ps[2] = trix + "," + bloy;
        ps[3] = trix + "," + triy;
        
        for (int i = 0; i < ps.length; i ++){
            if (!points.contains(ps[i]))
                return false;
        }
        return points.size() == 4 && (trix - blox) * (triy - bloy) == area;
    }
}
