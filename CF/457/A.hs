main = do
    line <- getLine
    let x = read line :: Int
    line <- getLine
    let t = words line
    let hh = t!!0
    let mm = t!!1
    putStrLn $ show (solve 0 hh mm x)

solve :: Int -> String -> String -> Int -> Int
solve ans hh mm x = if or ['7' `elem` hh, '7' `elem` mm] then
                        ans
                    else
                        solve (ans+1) (show $ nexth (read hh::Int) (read mm::Int)) (show $ nextm (read mm::Int)) x where
                            nextm m
                                | m >= x = m - x
                                | otherwise = m+60-x
                            nexth h m
                                | m >= x = h
                                | otherwise = if h==0 then 23 else h-1
