main = do
    line <- getLine
    putStrLn ((line) ++ (reverse line))
