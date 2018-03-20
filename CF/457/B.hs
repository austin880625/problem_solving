import Data.Bits
import Data.Maybe
-- import Debug.Trace
import qualified Data.Map as M
import qualified Data.Int as I
main = do
    line <- getLine
    let nk = words line
    let ans = solve (read (nk!!0)::I.Int64) (read (nk!!1)::Int)
    putStrLn (if (fst ans) then "Yes\n" ++ (printList $ snd ans) else "No")

printList :: (Show a) => [a] -> String
printList (x:[]) = show x
printList (x:xs) = (show x) ++ " " ++ printList xs 

solve :: I.Int64 -> Int -> (Bool, [Int])
solve 0 _ = (False, [])
solve n k = if (popCount n) > k then (False, [])
            else (True, toList (expand 0 k (genList 0 n) ) (0,0))

genList :: Int -> I.Int64 -> (M.Map Int Int)
genList _ 0 = M.empty
genList p n = if (n .&. 1::I.Int64)==0 then genList (p+1) (shiftR n 1) else M.insert p 1 $ genList (p+1) (shiftR n 1)

expand :: Int -> Int -> M.Map Int Int -> M.Map Int Int
expand 0 k m = expand (M.size m) k m
expand s k m = if k == s then m
                else let num = M.findMax m
                         newVal n x = if isNothing x then Just (2*n) else fmap (+2*n) x in
                    if (s + snd num) <= k then 
                        expand (s+(snd num)) k $ M.alter (newVal (snd num)) ((fst num)-1) (M.deleteMax m)
                    else let num2 = M.findMin m in
                        expand (s+1) k $ M.alter (newVal 1) ((fst num2)-1) $ M.adjust (\x->x-1) (fst num2) m

toList :: M.Map Int Int -> (Int, Int) -> [Int]
toList m (_, 0) = if M.size m == 0 then [] else toList (M.deleteMax m) (M.findMax m)
toList m (k, x) = k:toList m (k, x-1)
