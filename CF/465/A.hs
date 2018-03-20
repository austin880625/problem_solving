toInt :: IO [Int]
toInt = fmap (map read.words) getLine

main = do
   n <- fmap head toInt 
   s <- getLine
   putStrLn $ show $ f (0,0) (0,0) s

f :: (Integer,Integer) -> (Integer,Integer) -> String -> Int
f _ _ [] = 0
f (lastx,lasty) (x,y) (m:ms) = case m of 
                                            'U' -> if (lastx-lasty)*(x-y-1)<0 then 1+(f (x,y) (x,y+1) ms)
                                                                            else f (x,y) (x,y+1) ms
                                            'R' -> if (lastx-lasty)*(x+1-y)<0 then 1+(f (x,y) (x+1,y) ms)
                                                                            else f (x,y) (x+1,y) ms
