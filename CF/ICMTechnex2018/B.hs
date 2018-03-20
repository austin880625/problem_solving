toInt :: IO [Int]
toInt = fmap (map read.words) getLine
main = do
    let table = reverse $ genTable 1000001 ([[]])
    q <- fmap head toInt
    lrk <- toInt
    let l=lrk!!0
    let r=lrk!!1
    let k=lrk!!2
    putStrLn $ show $ ((table !! r !! k) - (table !! (l-1) !! k))

genTable :: Int -> [[Int]] -> [[Int]]
genTable k table
    | k == 0 = [replicate 10 0]
    | otherwise = let newTable = genTable (k-1) table in 
        (zipWith (+) row (head newTable))  : newTable where
            row = let t = g k in ((replicate (t) 0) ++ [1] ++(replicate (10-t) 0))

f :: Int -> Int
f n
    | n == 0 = 1
    | otherwise = let r = n `mod` 10 in if r == 0 then f (quot n 10)::Int else r*(f (quot n 10)::Int)

g :: Int -> Int
g n
    | n<10 = n
    | otherwise = (g.f) n
