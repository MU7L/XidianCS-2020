package Sort;

public class Monitor {
    private long startSpace;
    private long endSpace;
    private long startTime;
    private long endTime;
    public Monitor() {
        startSpace = 0;
        endSpace = 0;
        startTime = 0;
        endTime = 0;
    }
    public void start() {
        startSpace = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        startTime = System.currentTimeMillis();
    }
    public void end() {
        endSpace = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        endTime = System.currentTimeMillis();
    }
    public void clear() {
        startSpace = 0;
        endSpace = 0;
        startTime = 0;
        endTime = 0;
    }
    public double getTime() {
        return (endTime - startTime) / 1000.0;
    }
    public long getSpace() {
        return endSpace - startSpace;
    }
}
